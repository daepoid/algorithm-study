DROP TABLE IF EXISTS programmers.CAR_RENTAL_COMPANY_DISCOUNT_PLAN;
CREATE TABLE programmers.CAR_RENTAL_COMPANY_DISCOUNT_PLAN(
   plan_id       INTEGER  NOT NULL PRIMARY KEY
  ,car_type      VARCHAR(3) NOT NULL
  ,duration_type VARCHAR(6) NOT NULL
  ,discount_rate INTEGER  NOT NULL
);
INSERT INTO programmers.CAR_RENTAL_COMPANY_DISCOUNT_PLAN(plan_id,car_type,duration_type,discount_rate) VALUES (1,'세단','7일 이상',5);
INSERT INTO programmers.CAR_RENTAL_COMPANY_DISCOUNT_PLAN(plan_id,car_type,duration_type,discount_rate) VALUES (2,'세단','30일 이상',8);
INSERT INTO programmers.CAR_RENTAL_COMPANY_DISCOUNT_PLAN(plan_id,car_type,duration_type,discount_rate) VALUES (3,'세단','90일 이상',12);
INSERT INTO programmers.CAR_RENTAL_COMPANY_DISCOUNT_PLAN(plan_id,car_type,duration_type,discount_rate) VALUES (4,'SUV','7일 이상',3);
INSERT INTO programmers.CAR_RENTAL_COMPANY_DISCOUNT_PLAN(plan_id,car_type,duration_type,discount_rate) VALUES (5,'SUV','30일 이상',5);
INSERT INTO programmers.CAR_RENTAL_COMPANY_DISCOUNT_PLAN(plan_id,car_type,duration_type,discount_rate) VALUES (6,'SUV','90일 이상',10);
INSERT INTO programmers.CAR_RENTAL_COMPANY_DISCOUNT_PLAN(plan_id,car_type,duration_type,discount_rate) VALUES (7,'승합차','7일 이상',5);
INSERT INTO programmers.CAR_RENTAL_COMPANY_DISCOUNT_PLAN(plan_id,car_type,duration_type,discount_rate) VALUES (8,'승합차','30일 이상',10);
INSERT INTO programmers.CAR_RENTAL_COMPANY_DISCOUNT_PLAN(plan_id,car_type,duration_type,discount_rate) VALUES (9,'승합차','90일 이상',15);
INSERT INTO programmers.CAR_RENTAL_COMPANY_DISCOUNT_PLAN(plan_id,car_type,duration_type,discount_rate) VALUES (10,'트럭','7일 이상',5);
INSERT INTO programmers.CAR_RENTAL_COMPANY_DISCOUNT_PLAN(plan_id,car_type,duration_type,discount_rate) VALUES (11,'트럭','30일 이상',8);
INSERT INTO programmers.CAR_RENTAL_COMPANY_DISCOUNT_PLAN(plan_id,car_type,duration_type,discount_rate) VALUES (12,'트럭','90일 이상',15);
INSERT INTO programmers.CAR_RENTAL_COMPANY_DISCOUNT_PLAN(plan_id,car_type,duration_type,discount_rate) VALUES (13,'리무진','7일 이상',4);
INSERT INTO programmers.CAR_RENTAL_COMPANY_DISCOUNT_PLAN(plan_id,car_type,duration_type,discount_rate) VALUES (14,'리무진','30일 이상',8);
INSERT INTO programmers.CAR_RENTAL_COMPANY_DISCOUNT_PLAN(plan_id,car_type,duration_type,discount_rate) VALUES (15,'리무진','90일 이상',20);
