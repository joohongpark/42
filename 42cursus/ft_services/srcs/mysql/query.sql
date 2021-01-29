create user joopark@'%' identified by 'joopark';
create user wp_root@'%' identified by 'joopark';
create database wp_db default CHARACTER SET UTF8;
grant all privileges on *.* to joopark@'%';
grant all privileges on wp_db.* to wp_root@'%';
flush privileges;