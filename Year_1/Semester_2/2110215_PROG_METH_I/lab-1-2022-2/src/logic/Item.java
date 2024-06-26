package logic;

import exception.NameBlankException;

public class Item {

	private String itemName;
	private int price;

	// constructor
	public Item(String itemName) throws NameBlankException {
		// FILL CODE
		setItemName(itemName);
		setPrice(0);
	}

	public Item(String itemName, int price) throws NameBlankException {
		// FILL CODE
		setItemName(itemName);
		setPrice(price);
	}

	// methods
	public boolean equals(Item other) {
		// FILL CODE
		return this.itemName.equals(other.itemName);
	}

	public String toString() {
		// FILL CODE
		return this.itemName + " $" + this.price;
	}

	// getter & setter
	public String getItemName() {
		// FILL CODE
		return this.itemName;
	}

	public void setItemName(String itemName) throws NameBlankException {
		// FILL CODE
		if (itemName.isBlank())
			throw new NameBlankException();
		this.itemName = itemName;
	}

	public int getPrice() {
		// FILL CODE
		return this.price;
	}

	public void setPrice(int price) {
		this.price = Math.max(0, price);
	}

}
