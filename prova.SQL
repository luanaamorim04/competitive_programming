-- Luana Amorim Lima

-- a
create table Produto(
	codigo_produto int primary key,
	nome_produto varchar(255),
	custo_unitario float,
	categoria text[],
	data_validade date
);

create table Receita(
	codigo_receita int primary key,
	nome_receita varchar(255),
	custo_total int
);

create table Ingrediente(
	codigo_receita int foreign key references Receita(codigo_receita),
	codigo_p int foreign key references Produto(codigo_produto),
	quantidade int
);

-- b

insert into Receita values (1, "Bolo", 10);
insert into Receita values (2, "Brigadeiro", 5);
insert into Receita values (3, "Omelete", 10);
insert into Receita values (4, "Salada", 7);
insert into Receita values (5, "Chocolate", 10);

insert into Produto values (1, 'Manteiga', 2.50, 'Tempero', '10/10/2040');
insert into Produto values (2, 'Chocolate', 4, 'Doce', '10/10/2040');
insert into Produto values (2, 'Açucar', 1, 'Doce', '10/10/2040');
insert into Produto values (2, 'Sal', 1, 'Tempero', '10/10/2040');
insert into Produto values (2, 'Tomate', 4, 'Fruta', '10/10/2040');
insert into Produto values (2, 'Ovo', 4, 'Comida', '10/10/2040');
insert into Produto values (2, 'Arroz', 4, 'Grao', '10/10/2040');

insert into Ingrediente values (1, );
insert into Ingrediente values (1, );
insert into Ingrediente values (1, );
insert into Ingrediente values (1, );
insert into Ingrediente values (1, );


-- c

select nome_produto, custo_unitario, data_validade from Produto where custo_unitario < 10;

-- d

select * from Receita where custo_total is not null ;

-- e

select Ingrediente.codigo_p, Produto.nome_produto from Produto, Receita where Produto.codigo_produto = Ingediente.codigo_p;

-- e2

select Ingrediente.codigo_p, Produto.nome_produto from Produto left join Receita on Produto.codigo_produto = Ingediente.codigo_p;

-- f

select p.nome_produto from Produto as p , Receita as r, Ingrediente as i where i.codigo_p = p.codigo_produto and r.codigo_receita = i.codigo_receita and r.receita_nome = 'Brigadeiro';

-- f2

select p.nome_produto from Ingrediente as i inner join  Receita as r on r.codigo_receita = i.codigo_receita inner join  Produto as p on i.codigo_p = p.codigo_produto where r.receita_nome = 'Brigadeiro';

-- g

select codigo_porduto, nome_produto, custo_aumentado(custo_unitario*1.10) from Produto order by custo_aumentado desc;

-- h

select r.nome_receita from Ingrediente as i inner join Receita as r on r.codigo_receita = i.codigo_receita
inner join Produto as p on i.codigo_p =  p.codigo_produto where p.nome_produto in ('Açúcar Mascavo', 'Canela');

-- i

select r.nome_receita from Ingrediente as i inner join Receita as r on r.codigo_receita = i.codigo_receita
inner join Produto as p on i.codigo_p =  p.codigo_produto where p.nome_produto like '%Açúcar%';

-- j

select top 1 * from Produto order by custo_unitario desc;

-- k

select categoria, avg(custo_unitario) from Produto group by categoria having avg(custo_unitario) > 10;

-- l

select count(*) from Ingedientes as i inner join Receita as r on r.codigo_receita = i.codigo_receita inner join Produto as p on p.codigo_produto = i.codigo_p where and codigo_receita = 2;

-- m

select Produto.codigo_produto, Produto.nome_produto from Produto where codigo_produto not in (select codigo_p from Ingrediente where codigo_p = codigo_produto);

-- n 

update Produto set custo_unitario = custo_unitario*1.10 where (categoria = 'frutas') or (categoria = 'carboidratos');

-- o

delete from Produto where codigo_produto not in (select codigo_p from Ingrediente where codigo_p = codigo_produto);
















