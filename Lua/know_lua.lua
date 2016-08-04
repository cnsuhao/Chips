print("hello world!")

pt = print
pt('hello world again!')

print(print)

print '-------------------------------------------------------'

-- 不要在意下面的函数定义 
local function printValueAndType(value) 
    print("[Value]", value,  "[Type]",  type(value)) 
end 

local function newproxy( isTrue)
	-- body
end

-- 注意下面各个类型值的书写 
printValueAndType( nil ) 
printValueAndType( true ) 
printValueAndType( 123 ) 
printValueAndType( "Hello World" ) 
printValueAndType( function() end ) 
printValueAndType( {} ) 
printValueAndType( coroutine.create( function() end ) ) 
--printValueAndType( newproxy(true) )

print '-------------------------------------------------------'

a,b,c = 1,2
print (a,b,c)

a,b,c = 1,2,3,4,5
print(a,b,c)

print( "10 > 9", 10 > 9 ) 
print( "10 < 9", 10 < 9 ) 
print( "10 == 9", 10 == 9 ) 
print( "10 ~= 9", 10 ~= 9 )

print( "not 1", not 1 ) 
print( "not nil", not nil ) 
print( "1 and 2", 1 and 2 ) 
print(" 1 or 2", 1 or 2 )

a = 1 and print( "第一次调用print语句" ) 
a = 1 or print( "第二次调用print语句" ) 
a = false and print( "第三次调用print语句" ) 
a = false or print( "第四次调用print语句" )
--[[你会注意到，只有第一次和第四次的print函数被调用了，
lua在执行逻辑运算时，会根据前值判定，有没有必要取后值，
如果结果是前值的话，那么后值连计算都没有必要了。]]--

print( "print is " .. tostring( print ) ) 
print( "boolean is " .. tostring( true ) .. " and " .. tostring( false ) )

greet = function( name ) 
    print("你好 " .. name) 
end 

greet( "Kurapica" )  -- 你好 Kurapica























