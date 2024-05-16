# E. Liczby
> Dostępna pamięć: 8 MB

Zaprojektuj i zaimplementuj strukturę, która umożliwi przechowywanie zbioru liczb całkowitych 𝒫 i wykonywanie na nim opisanych poniżej operacji.
- **Insert(𝑥)**. Dodaje liczbę całkowitą 𝑥 do zbioru 𝒫. Jeśli 𝑥 już należy do 𝒫, nic się nie dzieje.
- **Delete(𝑥)**. Usuwa liczbę całkowitą 𝑥 ze zbioru 𝒫.
- **Upper(𝑥)**. Zwraca liczbę 𝑦 ∈ 𝒫, taką że 𝑦 ⩾ 𝑥 i 𝑦 jest najmniejszą liczbą o takiej własności.
- **Lower(𝑥)**. Zwraca liczbę 𝑦 ∈ 𝒫, taką że 𝑦 ⩽ 𝑥 i 𝑦 jest największą liczbą o takiej własności.

> **UWAGA**: W tym zadaniu zabronione jest używanie tych konstrukcji STL-a, których nazwy zawierają: set, map lub hash. Niedozwolone jest wykorzystanie gotowych odpowiedników tych konstrukcji w innych językach programowania.

## Specyfikacja danych wejściowych
W pierwszym wierszu danych wejściowych znajduje się liczba naturalna 𝑁 ∈ [1, 106], oznaczająca liczbę operacji na zbiorze 𝒫. 
Początkowo zbiór 𝒫 jest pusty. 

W każdym z kolejnych 𝑁 wierszy znajduje się opis jednej operacji wykonywanej na zbiorze 𝒫. Każdy z wierszy składa się z dużej litery ze zbioru {𝐼, 𝐷, 𝑈, 𝐿}, pojedynczego odstępu i liczby całkowitej 𝑥 ∈ [−1018, 1018]. Podana litera jest pierwszą literą operacji zdefiniowanych powyżej.

Operacje są tak dobrane, że po każdej z nich rozmiar zbioru wynosi co najwyżej 50 000.

## Specyfikacja danych wyjściowych
Twój program powinien wypisać jeden wiersz dla każdej operacji **Delete**, **Upper** lub **Lower**. Zawartość tego wiersza powinna być następująca: dla operacji **Delete(𝑥)** należy wypisać słowo **BRAK**, jeśli 𝑥 ∉ 𝒫 i **OK** w przeciwnym przypadku; zaś dla operacji **Upper** lub **Lower** należy wypisać znalezioną liczbę, a jeśli taka nie istnieje — słowo **BRAK**.

## Przykłady
### Przykład A
Wejście:
```
4
I 2
D 2
D 2
D 2
```
Wyjście:
```
OK
BRAK
BRAK
```
### Przykład B
Wejście:
```
7
I -2
I 0
L -4
L -2
L -1
L 0
L 3
```
Wyjście:
```
BRAK
-2
-2
0
0
```
### Przykład C
Wejście:
```
6
I 2
I 2
I 3
D 2
U 0
L 0
```
Wyjście:
```
OK
3
BRAK
```