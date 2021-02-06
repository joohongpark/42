#!/bin/bash

# 1. minikube 시작
minikube start --driver=hyperkit

# 2. minikube 환경변수 set
eval $(minikube docker-env)
IP=$(minikube ip)

# 3. 환경설정 파일 내용 변경
sed -i '' -e "s/CLUSTER_IP_ADDR/$IP/g" srcs/ftps/files/vsftpd.conf
sed -i '' -e "s/CLUSTER_IP_ADDR/$IP/g" srcs/metallb/metallb.yml
sed -i '' -e "s/CLUSTER_IP_ADDR/$IP/g" srcs/nginx/files/https.conf
sed -i '' -e "s/CLUSTER_IP_ADDR/$IP/g" srcs/mysql/files/wp_db.sql

# 4. dockerfile build
docker build -t "ft_services/wordpress:0.2" srcs/wordpress
docker build -t "ft_services/nginx:0.3" srcs/nginx
docker build -t "ft_services/phpmyadmin:0.4" srcs/phpmyadmin
docker build -t "ft_services/ftps:0.2" srcs/ftps
docker build -t "ft_services/grafana:0.2" srcs/grafana
docker build -t "ft_services/influxdb:0.2" srcs/influxdb
docker build -t "ft_services/mysql:0.4" srcs/mysql

# 5. Deployment apply
kubectl apply -f srcs/wordpress/wordpress_deploy.yml
kubectl apply -f srcs/nginx/nginx_deploy.yml
kubectl apply -f srcs/phpmyadmin/phpmyadmin_deploy.yml
kubectl apply -f srcs/ftps/ftps_deploy.yml
kubectl apply -f srcs/grafana/grafana_deploy.yml
kubectl apply -f srcs/influxdb/influxdb_deploy.yml
kubectl apply -f srcs/mysql/mysql_deploy.yml

# 5-1. Persistent Volume Clame apply
kubectl apply -f srcs/persistentvolume/pvc-mysql.yml

# 6. clusterip apply
kubectl apply -f srcs/clusterip/influxdb_clusterip.yml
kubectl apply -f srcs/clusterip/mysql_clusterip.yml
kubectl apply -f srcs/clusterip/phpmyadmin_clusterip.yml

# 7. MetalLB Enable & apply
minikube addons enable metallb
kubectl apply -f srcs/metallb/metallb.yml

# 8. LoadBalancer apply
kubectl apply -f srcs/loadbalancer/ftps_loadbalancer.yml
kubectl apply -f srcs/loadbalancer/grafana_loadbalancer.yml
kubectl apply -f srcs/loadbalancer/nginx_loadbalancer.yml
kubectl apply -f srcs/loadbalancer/phpmyadmin_loadbalancer.yml
kubectl apply -f srcs/loadbalancer/wordpress_loadbalancer.yml

# 9. 환경설정 파일 원복
sed -i '' -e "s/$IP/CLUSTER_IP_ADDR/g" srcs/ftps/files/vsftpd.conf
sed -i '' -e "s/$IP/CLUSTER_IP_ADDR/g" srcs/metallb/metallb.yml
sed -i '' -e "s/$IP/CLUSTER_IP_ADDR/g" srcs/nginx/files/https.conf
sed -i '' -e "s/$IP/CLUSTER_IP_ADDR/g" srcs/mysql/files/wp_db.sql