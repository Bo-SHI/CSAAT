other = {foo = 3}
t = setmetatable({}, {__index = other})
print(t.foo)

t2 = setmetatable({key1 = "value1"}, {
    __index = function(t2, key)
        if key == "key2" then
            return "metatable"
        else
            return nil
        end
    end
})

print(t2.key1, t2.key2)

t3 = setmetatable({key1 = "value1"}, {__index = {key2 = "metatable"}})
print(t3.key1, t3.key2)
