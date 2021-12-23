CREATE SCHEMA IF NOT EXISTS "Empresa"
    AUTHORIZATION "user";
    
CREATE TABLE IF NOT EXISTS "Empresa"."Departamento"
(
    coddep integer primary key,
    nome text COLLATE pg_catalog."default" NOT NULL,
    matgerente integer,
    datainicio date
);

CREATE TABLE IF NOT EXISTS "Empresa"."Empregado"
(
    matricula integer NOT NULL,
    nome text COLLATE pg_catalog."default",
    datanasc date,
    endereco text COLLATE pg_catalog."default",
    sexo text COLLATE pg_catalog."default",
    salario double precision,
    supervisor integer,
    depto integer,
    CONSTRAINT "matricula_pkey" PRIMARY KEY (matricula),
    CONSTRAINT "coddep_fk" FOREIGN KEY (depto)
        REFERENCES "Empresa"."Departamento"(coddep),
    CONSTRAINT "supervisor_fk" FOREIGN KEY (supervisor)
        REFERENCES "Empresa"."Empregado"(matricula)
);

CREATE TABLE IF NOT EXISTS "Empresa"."Projeto"
(
    codproj integer,
    nome text COLLATE pg_catalog."default" NOT NULL,
    local_ text COLLATE pg_catalog."default" NOT NULL,
    depto integer NOT NULL,
    CONSTRAINT "Projeto_pkey" PRIMARY KEY (codproj),
    CONSTRAINT "Projeto_fk" FOREIGN KEY (depto)
        REFERENCES "Empresa"."Departamento"(coddep)
);

CREATE TABLE IF NOT EXISTS "Empresa"."Alocacao"
(
    matric integer NOT NULL,
    codigop integer NOT NULL,
    horas double precision,
    CONSTRAINT "alocacao_pkey" PRIMARY KEY (matric, codigop),
    CONSTRAINT "matric_fk" FOREIGN KEY (matric)
        REFERENCES "Empresa"."Empregado"(matricula),
    CONSTRAINT "codigop_fk" FOREIGN KEY (codigop)
        REFERENCES "Empresa"."Projeto"(codproj)
);

ALTER TABLE IF EXISTS "Empresa"."Projeto"
    OWNER to "user";

ALTER TABLE IF EXISTS "Empresa"."Alocacao"
    OWNER to "user";

ALTER TABLE IF EXISTS "Empresa"."Empregado"
    OWNER to "user";

ALTER TABLE IF EXISTS "Empresa"."Departamento"
    OWNER to "user",
    ADD CONSTRAINT "gerente_fk" FOREIGN KEY (matgerente)
        REFERENCES "Empresa"."Empregado"(matricula);
