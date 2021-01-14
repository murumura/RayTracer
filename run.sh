#!/bin/bash
docker run  --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -it \
--privileged -v /dev/bus/usb:/dev/bus/usb \
-v $(pwd):/home/RayTracer \
-p 1235:8888 \
 --name raytracer_container raytracer-dev