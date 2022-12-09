#!/bin/sh
openocd -f interface/cmsis-dap.cfg -c "adapter speed 4000" -f target/rp2040.cfg

