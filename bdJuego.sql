DROP DATABASE IF EXISTS bdFireWater;
CREATE DATABASE bdFireWater;

USE bdFireWater;

CREATE TABLE jugador (
	id INT NOT NULL,
	username VARCHAR(60) NOT NULL,
	password VARCHAR (60) NOT NULL,
	PRIMARY KEY (id)
)ENGINE=InnoDB;

CREATE TABLE partida (
	id INT NOT NULL,
	mapa	VARCHAR(30) NOT NULL,
	fecha VARCHAR(10),
	hora VARCHAR(8),
	duracion INT, 
	resultado VARCHAR(15),
	PRIMARY KEY (id)
)ENGINE=InnoDB;

CREATE TABLE historial (
	id_j1 INT NOT NULL,
	id_j2 INT NOT NULL,
	id_p INT NOT NULL,
	puntosj1 INT,
	puntosj2 INT,
	FOREIGN KEY (id_j1)REFERENCES jugador(id),
	FOREIGN KEY (id_j2)REFERENCES jugador(id),
	FOREIGN KEY (id_p)REFERENCES partida(id)
)ENGINE=InnoDB;

INSERT INTO jugador VALUES(1,"Juan","123");
INSERT INTO jugador VALUES(2,"Maria","123");
INSERT INTO jugador VALUES(3,"Bernat","contraseña");


INSERT INTO partida VALUES(1,"templo","01/10/2022", "10:00:00", 120, "Superado");
INSERT INTO partida VALUES(2,"templo","01/10/2022", "11:50:00", 120, "Superado");
INSERT INTO partida VALUES(3,"campo","02/10/2022", "17:00:00", 180, "No Superado");

	
INSERT INTO historial VALUES(1,2,1,10,20);
INSERT INTO historial VALUES(3,1,2,100,10);
INSERT INTO historial VALUES(3,2,3,0,5);
