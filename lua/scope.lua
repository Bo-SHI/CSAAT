local var = {}

local function lf()
    var.m = 1
end

function init()
    lf()
    print (var.m)
end

init()

