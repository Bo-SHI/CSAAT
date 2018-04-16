#! /bin/bash

VAR="Global variable"

function bash {
local VAR="Local variable"
echo ${VAR}
}

echo ${VAR}

bash

echo ${VAR}
