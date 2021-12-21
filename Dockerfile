FROM debian:latest

LABEL "https://github.com/bud-ea/exam_Tech_Prog3"="Repo"

RUN apt update && apt install build-essential && apt-get install manpages-dev && gcc --version

COPY . /MyProj
