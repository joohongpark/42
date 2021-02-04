#!/bin/bash

# 1. minikube 시작
#minikube start

# 2. minikube 환경변수 set
#eval $(minikube docker-env)
IP=$(minikube ip)

# 3. 환경설정 파일 내용 변경
sed -i '' -e "s/CLUSTER_IP_ADDR/$IP/g" srcs/ftps/files/vsftpd.conf
sed -i '' -e "s/CLUSTER_IP_ADDR/$IP/g" srcs/metallb/metallb.yml
sed -i '' -e "s/CLUSTER_IP_ADDR/$IP/g" srcs/nginx/files/https.conf