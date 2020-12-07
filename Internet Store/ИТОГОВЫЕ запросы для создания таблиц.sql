--
-- Файл сгенерирован с помощью SQLiteStudio v3.2.1 в пн дек. 7 17:45:27 2020
--
-- Использованная кодировка текста: UTF-8
--
PRAGMA foreign_keys = off;
BEGIN TRANSACTION;

-- Таблица: catalog
CREATE TABLE catalog ("code section" INTEGER NOT NULL PRIMARY KEY, "name section" TEXT NOT NULL, parent_id INTEGER REFERENCES catalog ("code section"));

-- Таблица: client
CREATE TABLE client (sc_id INTEGER PRIMARY KEY, fio TEXT NOT NULL, address TEXT NOT NULL, rating INTEGER);

-- Таблица: description
CREATE TABLE description (pd_id INTEGER PRIMARY KEY NOT NULL, text TEXT NOT NULL, title TEXT NOT NULL, "customer review" TEXT, "code section" TEXT REFERENCES catalog ("code section") NOT NULL);

-- Таблица: instance
CREATE TABLE instance (pi_id INTEGER PRIMARY KEY NOT NULL, description TEXT REFERENCES description (pd_id) NOT NULL, "order id" INTEGER REFERENCES "order" (uo_id));

-- Таблица: order
CREATE TABLE "order" (uo_id INTEGER PRIMARY KEY, sc_id INTEGER NOT NULL REFERENCES client (sc_id), "order date" TEXT NOT NULL, status TEXT);

-- Индекс: ix1
CREATE INDEX ix1 ON catalog (parent_id);

-- Индекс: ix2
CREATE INDEX ix2 ON client (fio);

-- Индекс: ix3
CREATE INDEX ix3 ON catalog ("name section");

-- Индекс: ix4
CREATE INDEX ix4 ON instance (description);

-- Индекс: ix5
CREATE INDEX ix5 ON instance ("order id");

-- Индекс: ix6
CREATE INDEX ix6 ON description ("code section");

-- Индекс: ix7
CREATE INDEX ix7 ON "order" (sc_id);

COMMIT TRANSACTION;
PRAGMA foreign_keys = on;
