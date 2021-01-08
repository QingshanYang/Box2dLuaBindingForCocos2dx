--[[

Copyright (c) 2012-2013 Baby-Bus.com

http://www.baby-bus.com/LizardMan/

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

]]

--[[!--

场景类，定义场景相关操作方法及逻辑实现。

-   定义场景功能方法。

]]

----------------------
-- 类
----------------------
local M = classScene("box2d")


----------------------
-- 公共参数
----------------------
-- [常量]
-- ..

-- [操作变量]
-- ..








----------------------
-- 构造方法
----------------------
--[[--

构造方法，定义视图实例初始化逻辑

### Parameters:
-   table **params**    参数集合

### Return: 
-   object              对象实例

]]
function M:ctor(params)
	M.super.ctor(self, params)
	-- [超类调用]
	self:assertParameters(params)

end





----------------------
-- 视图渲染
----------------------
--[[--

视图渲染，处理视图结点加载、事件绑定等相关操作

]]
function M:onRender()
	print("Hello Guy!") 

end







----------------------
-- 结点析构
----------------------
function M:onDestructor()
  M.super.onDestructor(self)
end




----------------------
-- 模板方法
----------------------
--[[--

获得层名称集合, 用于动态定义该场景需要加载的层

### Returns: 
-   string...       	层名称1, 层名称2, ...

]]
function M:getLayerNames()
    return "background","main","button"
end

--[[--

获得获得信息集合, 用于动态定义该场景需要加载的资源(纹理, 帧等)

### Returns: 
-   string|table...    	帧名称1|{资源名称,类型,自动清理,图片后缀(包含.)}, ...

]]
function M:getResourceNames()
    return 
end









----------------------
-- 验证
----------------------
-- 验证参数
function M:assertParameters(params)

end

-- --资源自动清理标识
-- function M:isAutoCleanupImages()
-- 	return true
-- end

-- 是否是开场动画
function M:isWelcomeScene()
	return true
end

----------------------
-- 过度动画开始之前的调用
----------------------
--[[--

1.资源释放，退出场景前的操作准备
2.处理视图结点卸载、事件解除绑定等相关操作

]]
function M:onExitTransitionStart()

end

return M