FROM ubuntu:24.04

RUN apt update
RUN apt -y install mc
RUN apt -y install g++ gcc git
RUN apt -y install cmake
RUN apt -y install gdb

ARG PROJECTS_DIR=/home/user/projects
RUN mkdir -p ${PROJECTS_DIR}

WORKDIR ${PROJECTS_DIR}

COPY problems_and_tests problems_and_tests


ARG PROBLEMS_DIR=${PROJECTS_DIR}/problems_and_tests

WORKDIR ${PROBLEMS_DIR}
#Configure
RUN cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug

#Build project
RUN cmake --build build  -j 4