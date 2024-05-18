package entity.ingredient;

import entity.base.Cookable;
import entity.base.Ingredient;
import logic.StringUtil;

public class Egg extends Ingredient implements Cookable {
	private int cookedPercentage;
	public Egg() {
		super("Egg");
		this.cookedPercentage = 0;
	}
	@Override
	public void cook() {
		setCookedPercentage(getCookedPercentage() + 12); 
		if(cookedPercentage > 100) {
			setName("Burnt Egg");
			setEdible(false);
		}
		else if(cookedPercentage > 80) {
			setName("Fried Egg");
			setEdible(true);	
		}
		else if(cookedPercentage > 50) {
			setName("Sunny Side Egg");
			setEdible(true);
		}
		else {
			setName("Raw Egg");
			setEdible(false);
		}
	}
	
	@Override
	public boolean isBurnt() {
		return cookedPercentage > 100;
	}
	
	@Override
	public String toString() {
		return StringUtil.formatNamePercentage(getName(), cookedPercentage);
	}
	
	// getter and setter
	public int getCookedPercentage() {
		return cookedPercentage;
	}
	public void setCookedPercentage(int cookedPercentage) {
		this.cookedPercentage = cookedPercentage;
	}
}
