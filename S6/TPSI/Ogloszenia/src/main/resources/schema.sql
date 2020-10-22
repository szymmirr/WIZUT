-- inicjalizacja bazy danych: tworzenie tabel

create table car_manufacturer (
	id integer auto_increment primary key,
	name varchar(30)
);

create table car_model (
	id integer auto_increment primary key,
	name varchar(30),
	manufacturer_id integer,
	foreign key (manufacturer_id) references car_manufacturer(id)
);

create table fuel_type (
	id integer auto_increment primary key,
	name varchar(30)
);

create table body_style (
	id integer auto_increment primary key,
	name varchar(30)
);

create table user (
	id integer auto_increment primary key,
	username varchar(30) not null,
	email varchar(30) not null,
	password varchar(255) not null
);

create table offer (
	id integer auto_increment primary key,
	title varchar(255),
	model_id integer,
	body_style_id integer,
	fuel_type_id integer,
	year integer,
	mileage integer,
	engine_size numeric(3,1),
	engine_power integer,
	doors integer,
	colour varchar(30),
	description text,
        price integer,
	user_id integer,
	foreign key(model_id) references car_model(id),
	foreign key(body_style_id) references body_style(id),
	foreign key(fuel_type_id) references fuel_type(id),
	foreign key(user_id) references user(id)
);

