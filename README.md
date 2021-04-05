# Warehouse Manager
Program designed to manage multiple warehouses and items inside them. Allows user to restock items, add new ones, sell and move them between warehouses. 

# Main Menu
- 0 exits the program
- 1 opens another menu where you can manage warehouses directly
- 2 opens menu where you can manage pallet trucks which are designed to move items between warehouses
- 3 displays all warehouses and their items
- 4 displays all pallet trucks and their load

# Submenus
### Warehouse Menu
- 0 return to main menu
- 1 create new warehouse
- 2 manage items in warehous

### Pallet truck Menu
- 0 return to main menu
- 1 create new pallet truck
- 2 display all pallet trucks
- 3 load items on concrete pallet truck
- 4 unload items from concrete pallet truck to concrete warehouse

# Premises

Moving products around is handled in a way that each pallet truck has its own maximum load and it can not be exceeded. 

Each type of product has its own weight too. 

User can not take more products from a warehouse than exist there and can not unload more than is currently loaded on a pallet truck. 

When user unloads the exact amount that is loaded (example: we have 50 items loaded and user unloads 50) instead of setting amount to 0, item is completly removed from pallet truck's vector of items. 

When unloading to a warehouse, products with the same ID are merged together and when there is no product with such ID new one is created.
