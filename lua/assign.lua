local mod = { watch_dog = {}}

local type = 1
if not mod.watch_dog[type] then
    mod.watch_dog[type] = {}
    mod.watch_dog[type].count = 100
end

print(mod.watch_dog[type])
print(mod.watch_dog[type].count)
