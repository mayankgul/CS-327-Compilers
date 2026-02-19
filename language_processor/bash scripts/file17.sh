#!/bin/bash
_var_1_9=22
_var_9_2=7

_in_teger_part=$(($_var_1_9/$_var_9_2)) #integer division
remainder=$(($_var_1_9%$_var_9_2)) #modular division

echo $_in_teger_part
echo $remainder
