% Flores Lara Alberto; Luna Zamora Juan Antonio; Saucillo González Jesse Obed 	3BV2

% Facts: parent(Child, Parent)
parent(john, mary).
parent(john, mike).
parent(mary, alice).
parent(mary, george).
parent(mike, lisa).
parent(mike, james).
parent(susan, alice).
parent(susan, george).
parent(lisa, carol).
parent(lisa, paul).
parent(james, karen).
parent(james, daniel).

% Rule: grandparent(Grandchild, Grandparent)
grandparent(Grandchild, Grandparent) :-
    parent(Grandchild, Parent),
    parent(Parent, Grandparent).

% Rule: sibling(Person1, Person2)
sibling(Person1, Person2) :-
    parent(Person1, Parent),
    parent(Person2, Parent),
    Person1 \= Person2.

% Rule: cousin(Person1, Person2)
cousin(Person1, Person2) :-
    parent(Person1, Parent1),
    parent(Person2, Parent2),
    sibling(Parent1, Parent2).

% Rule: bisabuelo(Bisabuelo, Nieto)
bisabuelo(Bisabuelo, Nieto) :-
    parent(Nieto, Padre),
    parent(Padre, Abuelo),
    parent(Abuelo, Bisabuelo).

% Rule: tatarabuelo(Tatarabuelo, Descendiente)
tatarabuelo(Tatarabuelo, Descendiente) :-
    parent(Descendiente, Hijx),
    parent(Hijx, Nietx),
    parent(Nietx, Bisnietx),
    parent(Bisnietx, Tatarabuelo).

% Rule: sobrino(Sobrino, TioTia)
sobrino(Sobrino, TioTia) :-
    sibling(Sobrino, PadreOMadre),
    parent(PadreOMadre, TioTia).