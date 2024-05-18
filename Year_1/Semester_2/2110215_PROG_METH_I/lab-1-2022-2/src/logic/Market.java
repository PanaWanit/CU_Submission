package logic;

import java.util.ArrayList;

public class Market {

	// fields
	ArrayList<Item> allItems;

	// constructors
	public Market() {
		//FILL CODE
		setAllItems(new ArrayList<Item>());
	}

	public Market(ArrayList<Item> items) {
		//FILL CODE
		setAllItems(new ArrayList<Item>());
		addAllItems(items);
	}

	// methods
	public String toString() {
		String out = "\n";
		for (int i = 0; i < allItems.size(); i++) {
			out += i + 1;
			out += ". ";
			out += allItems.get(i).toString();
			out += "\n";
		}
		return out;
	}

	public void addAllItems(ArrayList<Item> items) {
		if(items == null)
			return;
		//FILL CODE
		for(Item it : items) {
			boolean duplicate = false;
			for(Item ch : allItems) {
				duplicate |= ch.equals(it);
			}
//			System.out.println(duplicate);
			if(duplicate) {
				System.out.println("\""+ it.getItemName() + "\" is duplicated, Item will not be added.");
			}
			else {
				System.out.println("\""+ it + "\" Added to the market.");
				allItems.add(it);
			}
		}
	}


	//getter setters 
	//FILL CODE
	public ArrayList<Item> getAllItems() {
		return allItems;
	}

	public void setAllItems(ArrayList<Item> allItems) {
		this.allItems = allItems;
	}
}
