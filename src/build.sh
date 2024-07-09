#!/bin/bash
set -e

make "INAV-X-Plane-HITL"

#ldd build/INAV-X-Plane-HITL/64/mac.xpl

#objdump -x build/INAV-X-Plane-HITL/64/mac.xpl