package logic;

public class ItemCounter {
	private Item item;
	private int amount;
	public ItemCounter(Item item) {
		setItem(item);
		setCount(1);
	}
	public ItemCounter(Item item, int amount) {
		setItem(item);
		setCount(Math.max(1, amount));
	}
	public String toString() {
		return item + " x" + amount;
	}
	
	public Item getItem() {
		return this.item;
	}
	public void setItem(Item item) {
		this.item = item;
	}

	public int getCount() {
		return this.amount;
	}
	public void setCount(int amount) {
		this.amount = Math.max(0, amount);
	}

}
