CREATE DATABASE epytodo;

CREATE TABLE epytodo.user (
  id INT NOT NULL AUTO_INCREMENT,
  email VARCHAR(45) UNIQUE NOT NULL,
  password VARCHAR(45) NOT NULL,
  name VARCHAR(45) NOT NULL,
  firstname VARCHAR(45) NOT NULL,
  created_at DATETIME,
  PRIMARY KEY (id)); 

CREATE TABLE epytodo.todo (
  id INT NOT NULL AUTO_INCREMENT,
  title VARCHAR(45) NOT NULL,
  description VARCHAR(45) NOT NULL,
  created_at DATETIME,
  due_time DATETIME NOT NULL,
  status VARCHAR(45) NOT NULL,
  user_id INT UNSIGNED,
  PRIMARY KEY (id));
