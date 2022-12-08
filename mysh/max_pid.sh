#!/bin/bash

awk '{ print $1 }' /proc/sys/kernel/pid_max
