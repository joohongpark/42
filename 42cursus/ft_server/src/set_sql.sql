create user 'joopark'@'localhost' identified by 'joopark';
create user wp_root@'localhost' identified by 'joopark';
create database wp_db default CHARACTER SET UTF8;
grant all privileges on *.* to joopark@'localhost';
grant all privileges on wp_db.* to wp_root@'localhost';
flush privileges;