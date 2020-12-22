"# Warehouse" 
Po włączeniu programu użytkownik dostaje menu z pięcioma opcjami obsługi magazynu. (0-5)
Zaczynając od '0' - kończy ona program.
Pod '1' użytkownik przechodzi do kolejnego menu zarządzania magazynami, może on tam:
- wrócić do menu głównego
- stworzyć nowy magazyn
- zarządzać produktami w magazynie, czyli przejść do kolejnego menu, gdzie można stworzyć Produkt jednego z dostępnych typów oraz manipulować ilością tych produktów,
- wypisać konkretny magazyn.

Pod '2' mamy dostęp do menu zarządzania Paleciakami.
- stworzenie paleciaka,
- wypisanie paleciaka,
- zaladowanie paleciaka,
- rozladowanie paleciaka.

Można tworzyć wiele paleciaków.

Aby zaladowac produkt na paleciak, uzytkownik musi sprecyzowac na którym magazynie i na którym paleciaku chce pracować. Potem musi wybrać konkretne ID danego produktu oraz jego ilość, która ma zostać umieszczona na paleciak.

Aby rozładować paleciak użytkownik musi sprecyzowac na którym paleciaku chce pracować i do którego magazynu chce go rozładować. Potem musi podać ID oraz ilość danego Produktu do rozładowania. Gdy zdecyduje się on rozładować cały towar zostanie on usunięty z paleciaka i zostanie na nim zwolnione miejsce. Jeżeli w danym magazynie nie było jeszcze towaru z ID Produktu który ma zostać tam rozładowany zostanie utworzony taki Produkt w danym magaazynie. Natomiast jeżeli Produkt z takim ID już istniej, jego ilość z paleciaka zostanie przyłączona do tej w magazynie.