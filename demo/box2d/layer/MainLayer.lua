
local M = classLayerTouch("Main")

local box2d = require("com.zbox2d")


--------------------------
-- 构造函数
--------------------------

function M:ctor(params)
    -- [超类调用]
    M.super.ctor(self, params)
    -- [本类调用]
    self.isApplyForce = false
    self.posTable = {}
    self.segmentsList = {}
end

--------------------------
-- 渲染
--------------------------

function M:onRender()
    -- [超类调用]
    M.super.onRender(self)

    -- [本类调用]
    -- 加载节点
    self:loadNodes()
    -- 碰撞筛选器测试 --
    self:loadPlatform()
end

-- 加载节点
function M:loadNodes()
    self.world = b2World(b2Vec2(0, -9.8))
    self:createWorldEdge()
    -- 调试模式
    local debugDraw = GB2DebugDrawLayer:create(self.world, PTM_RATIO)
    self:add(debugDraw, 9999)
    -- 开启物理迭代
    self:update()
    -- 监听注册
    self:registContactListener()
end

-- 加载渲染以外的其他操作
function M:onEnterTransitionFinish()

end

-- - 创建世界边缘
function M:createWorldEdge()
    local function createEdge(body, point1, point2)
        local fixtureDef = b2FixtureDef()
        local edgeType = b2EdgeShape()
        edgeType:Set(b2Vec2(point1.x/PTM_RATIO, point1.y/PTM_RATIO), b2Vec2(point2.x/PTM_RATIO, point2.y/PTM_RATIO));
        fixtureDef.shape       = edgeType
        body:CreateFixture(fixtureDef)
    end

    local bodyDef      = b2BodyDef()
    local body         =  self.world :CreateBody(bodyDef)
    createEdge(body, cc.p(0, 0), cc.p(V.w, 0))
    createEdge(body, cc.p(0, 0), cc.p(0, V.h))
    createEdge(body, cc.p(0, V.h), cc.p(V.w, V.h))
    createEdge(body, cc.p(V.w, 0), cc.p(V.w, V.h))
end

-- 添加一个碰撞监听
function M:registContactListener()
    self._listener = GB2ContactListener:new_local()
    -- 为接触监听函数注册函数
    self._listener:registerScriptHandler(function(contactType, contact, oldManifold)
        -- self:contactListener(contactType, contact, oldManifold)
        -- print("===为接触监听函数注册函数====", contactType)
    end)
    self.world:SetContactListener(self._listener)

end

function M:update(delegateTick)
    -- 开启延时器进行物理更新
    local timer = scheduler.scheduleUpdateGlobal(function (dt)
        local callBack = delegateTick or M.tick
        self:tick(dt)
    end)
    return timer
end

-- 更新[物理世界]
function M:tick(dt)
    if not  self.world then return end
    -- 速度迭代device、位置迭代
    -- 迭代次数越多越真实，但是性能越低。
    -- 为了模拟真实我一般都是设置成32，但是这款项目刚体过多，模拟比较耗性能，索引改成8和1，网上也有人建议设置为10.
    local velocityIterations, positionIterations = 10, 10
    -- 时间步
     self.world.timeStep = dt or M.getTimeStep()
    -- 物理引擎进行物理模拟，生成模拟后的数据
     self.world:Step( self.world.timeStep, velocityIterations, positionIterations)

    self.world:ClearForces()
    -- 同步物理世界和渲染世界
    local body =  self.world:GetBodyList()
    while body do
        if body:GetUserData() then
            local spr = tolua.cast(body:GetUserData(), "cc.Sprite")
            local x, y = body:GetPosition().x * PTM_RATIO, body:GetPosition().y * PTM_RATIO
            -- 更新位置、角度，同步物理世界和渲染世界
            spr:setPosition(ccp(x, y))
            spr:setRotation(-1 * PT.radians2degrees(body:GetAngle()))
        end
        -- 获得下一个body
        body = body:GetNext()
    end
  
end




------------------------------ 碰撞筛选器测试 begin -----------------------------
function M:loadPlatform()
   local bodyDef      = b2BodyDef()
    bodyDef.position   = b2Vec2(V.w_2 / PTM_RATIO, 92 / PTM_RATIO)
    --动态刚体 b2_dynamicBody,静态刚体 b2_staticBody,平台刚体 b2_kinematicBody
    bodyDef.type       = b2_staticBody
    --允许休眠
    bodyDef.allowSleep = true
    local body         = self.world:CreateBody(bodyDef)
    --创建夹具定义
    local fixtureDef = b2FixtureDef()
    --创建一个多边形
    local shape = b2PolygonShape()
    shape:SetAsBox(360 / PTM_RATIO, 32 / PTM_RATIO)
    --赋值给材质的属性
    fixtureDef.shape       = shape
    --摩擦
    fixtureDef.friction    = .3
    --恢复
    fixtureDef.restitution = .2
    --密度
    fixtureDef.density     = .3
    -- local filer = b2Filter()
    -- filer.categoryBits = 0x0010
    -- filer.maskBits = 0x0100
    -- fixtureDef.filter = filer
    local a = body:CreateFixture(fixtureDef)
    local shape = a:GetShape()
    self.platformBody = body
    self:body1()
    -- self:body2()
end

function M:body1()
    local bodyDef      = b2BodyDef()
    bodyDef.position   = b2Vec2(320 / PTM_RATIO, 360 / PTM_RATIO)
    --动态刚体 b2_dynamicBody,静态刚体 b2_staticBody,平台刚体 b2_kinematicBody
    bodyDef.type       = b2_dynamicBody
    --允许休眠
    bodyDef.allowSleep = false
    local body         = self.world:CreateBody(bodyDef)
    --创建夹具定义
    local fixtureDef = b2FixtureDef()
    --创建一个多边形
    local shape = b2PolygonShape()
    shape:SetAsBox(32 / PTM_RATIO, 32 / PTM_RATIO)
    --赋值给材质的属性
    fixtureDef.shape       = shape
    --摩擦
    fixtureDef.friction    = .3
    --恢复
    fixtureDef.restitution = .2
    --密度
    fixtureDef.density     = .3
    --用户数据
    local filer = b2Filter()
    -- filer.categoryBits = 0x0110
    -- filer.maskBits = 0x1000
    -- fixtureDef.filter = filer
    body:CreateFixture(fixtureDef)
    print(body:GetLinearVelocity(), tolua.type(body:GetLinearVelocity()))
    body:GetWorldPoint(body:GetLinearVelocity())
    body:SetLinearVelocity(b2Vec2(1, 0))
    self.body = body
end

-------------------------------- 创建鼠标关节--------------------------------
function M:createMouseJoint(bodyA, bodyB, jointInfo)
    -- 创建一个鼠标关节定义
    local mouseJointDef            = b2MouseJointDef()
    -- 关节连接的刚体A
    mouseJointDef.bodyA            = bodyA
    -- 关节连接的刚体B
    mouseJointDef.bodyB            = bodyB
    -- 关节连接在刚体A上的锚点，其他关节应该也有，默认在中央
    mouseJointDef.localAnchorA     = b2Vec2(0.5, 0.5)
    -- 关节连接在刚体B上的锚点，其他关节应该也有，默认在中央
    mouseJointDef.localAnchorB     = b2Vec2(0.5, 0.5)
    -- 频率：频率越高，关节越硬。影响关节的弹性（典型情况下，关节频率要小于一半的时间步(time step)频率。
    --  比如每秒执行60次时间步, 关节的频率就要小于30赫兹。这样做的理由可以参考Nyquist频率理论。）
    mouseJointDef.frequencyHz      = 30
    -- 阻尼率：值越大，关节运动阻尼越大。影响关节的弹性（阻尼率无单位，典型是在0到1之间, 也可以更大。1是阻尼率的临界值, 当阻尼率为1时，没有振动。）
    mouseJointDef.dampingRatio     =  1
    -- 是否连续碰撞
    mouseJointDef.collideConnected = true
    -- 作用点
    mouseJointDef.target           = b2Vec2(jointInfo.target.x / PTM_RATIO, jointInfo.target.y / PTM_RATIO)
    -- 限制关节上可以施加的最大的力
    mouseJointDef.maxForce         = 100000
    -- 创建关节，并转换为b2MouseJoint类型   
    return tolua.cast(self.world:CreateJoint(mouseJointDef), "b2MouseJoint")
end
--------------------------
-- 触控
-------------------------- 

function M:onTouchBegan(x, y, touches)
    local fixtrue = self.body:GetFixtureList()
    local res = fixtrue:TestPoint(b2Vec2(x / PTM_RATIO, y/PTM_RATIO))
    if res and not self.joint then
        self.joint = self:createMouseJoint(self.platformBody, self.body, {target = cc.p(x, y), maxForce = 10000})
    end
    return true 
end

function M:onTouchMoved(x, y, touches)
    if self.joint then
        self.joint:SetTarget(b2Vec2(x / PTM_RATIO, y / PTM_RATIO))
    end
end

function M:onTouchEnded(x, y, touches)
    if self.joint then
        self.world:DestroyJoint(self.joint)
        self.joint = nil
    end
end



--------------------------
-- 功能函数
--------------------------




--------------------------
-- 属性
--------------------------




--------------------------
-- 父类重写
--------------------------




----------------------------------------------------
-- 析构
--------------------------

function M:onDestructor()
    -- [超类调用]
    M.super.onDestructor(self)
    -- [本类调用]

end








return M






