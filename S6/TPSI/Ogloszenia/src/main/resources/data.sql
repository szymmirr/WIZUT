-- inicjalizacja bazy danych: przykładowe dane

insert into user(username, email, password) values
('admin', 'admin@localhost', hash('SHA256', stringtoutf8('kaszanka'), 1)),
('student', 'student@wizut', hash('SHA256', stringtoutf8('pandatrzy'), 1)),
('user', 'user@localhost', hash('SHA256', stringtoutf8('user'), 1));

insert into car_manufacturer(name) values
('Alfa Romeo'), ('Audi'), ('Nissan'), ('Mazda'), ('Toyota'), ('Lexus'), 
('Honda'), ('Skoda'), ('Volkswagen'), ('Jaguar'), ('Ford'), ('BMW');

insert into car_model(name, manufacturer_id) values
('156', 1), ('166', 1), ('159', 1), ('Brera', 1), ('Spider', 1), 
('A3', 2), ('A4', 2), ('A6', 2), ('A8', 2),
('Primera', 3), ('Almera', 3), ('Sunny', 3), ('Bluebird', 3), ('X-Trail', 3), ('Pathfinder', 3), ('Micra', 3), ('Maxima', 3),
('323', 4), ('626', 4), ('3', 4), ('6', 4), ('MX-5', 4), ('CX-5', 4), 
('Corolla', 5), ('Yaris', 5), ('Avensis', 5), ('Auris', 5), 
('NX', 6), ('RX', 6), ('GS', 6), ('IS', 6), 
('Accord', 7), ('Civic', 7), ('Jazz', 7), ('HR-V', 7), 
('Fabia', 8), ('Octavia', 8), ('Superb', 8), ('Rapid', 8), ('Yeti', 8), 
('Golf', 9), ('Passat', 9), ('Polo', 9), ('Up', 9), ('Scirocco', 9), ('Phaeton', 9), 
('F-Pace', 10), ('F-Type', 10), ('XE', 10), ('XF', 10), ('XJ', 10), 
('Fiesta', 11), ('Focus', 11), ('Mondeo', 11), ('Kuga', 11), ('Mustang', 11), ('F-150', 11), ('GT', 11),
('Seria 3', 12), ('Seria 5', 12), ('Seria 7', 12), ('X5', 12), ('Z3', 12), ('M5', 12);

insert into fuel_type(name) values
('Benzyna'), ('Diesel'), ('LPG'), ('CNG'), ('Wodór'), ('Hybrydowy'), ('Elektryczny');

insert into body_style(name) values
('Hatchback'), ('Sedan'), ('Coupe'), ('Kombi'), ('SUV'), ('Pickup'), ('Kabriolet'), ('Terenowy');

insert into offer(title, model_id, body_style_id, fuel_type_id, year, mileage, engine_size, engine_power, doors, colour, description, price, user_id) values
(
'Nissan Primera P11.144', 10, 1, 1, 2000, 152000, 1.6, 100, 5, 'wiśniowy',
'Nie sprzedam za nic w świecie, proszę nie dzwonić i nie pytać. Pokazuję zdjęcia, żeby się pochwalić.', 0, 1
),
(
'Nissan Bluebird', 13, 2, 2, 1988, 352000, 2.0, 75, 4, 'biały',
'Zadbany klasyk, dla koneserów. Klimatyzacja automatyczna, komputer pokładowy, nawigacja satelitarna, podgrzewane siedzenia, system kontroli trakcji - tych ani żadnych innych zbędnych bzdetów to auto nie posiada.', 2500, 1
),
(
'BMW 316 aka Dresowóz Klasyk', 59, 2, 1, 1991, 452000, 1.8, 110, 4, 'czarny',
'W komplecie dresy Adidas, kij bejzbolowy i alibi na najbliższy weekend.', 1750, 3
),
(
'Honda Jazz zadbana', 34, 1, 2, 2012, 17000, 1.2, 90, 3, 'błękitny',
'Niemiecki dziadek jeździł do kościoła i na działkę. Niepalona, niebita, serwisowana w ASO.', 22500, 2
);
