package entity.container;

import entity.base.Container;
import entity.base.Ingredient;
import logic.StringUtil;

public class Dish extends Container {
	private int dirty;
	
	public Dish() {
		super("Dish", 4);
		setDirty(0);
	}
	
	public Dish(int dirty) {
		super("Dish", 4);
		setDirty(dirty);
	}
	
	public boolean isDirty() {
		return getDirty() > 0;
	}

	public void clean(int amount) {
		setDirty(getDirty() - amount); 
	}
	
	@Override
	public String toString() {
		if(isDirty())
			return StringUtil.formatNamePercentage(getName(), getDirty());
		return super.toString();
	}
	
	// getter and setter
	public int getDirty() {
		return dirty;
	}

	public void setDirty(int dirty) {
		this.dirty = Math.max(dirty, 0);
		if(isDirty())
			setName("Dirty Dish");
		else
			setName("Dish");
	}

	@Override
	public boolean verifyContent(Ingredient i) {
		return !isDirty() && i.isEdible();
	}
	
}
