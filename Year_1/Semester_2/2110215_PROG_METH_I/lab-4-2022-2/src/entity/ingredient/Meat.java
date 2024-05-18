package entity.ingredient;

import entity.base.Choppable;
import entity.base.Cookable;
import entity.base.Ingredient;
import logic.StringUtil;

public class Meat extends Ingredient implements Choppable, Cookable {
	private boolean chopState;
	private int cookedPercentage;
	public Meat() {
		super("Meat");
		this.chopState = false;
		this.cookedPercentage = 0;
	}

	@Override
	public void cook() {
		if(isChopped()) {
			cookedPercentage += 15;
			if(cookedPercentage > 100) {
				setName("Burnt Burger");
				setEdible(false);
			}
			else if(cookedPercentage > 80) {
				setName("Cooked Burger");
				setEdible(true);	
			}
			else {
				setName("Raw Burger");
				setEdible(false);
			}
			return;
		}
		cookedPercentage += 10;
		if(cookedPercentage > 100) {
			setName("Burnt Steak");
			setEdible(false);
		}
		else if(cookedPercentage > 80) {
			setName("Well Done Steak");
			setEdible(true);	
		}
		else if(cookedPercentage > 50) {
			setName("Medium Rare Steak");
			setEdible(true);
		}
		else {
			setName("Raw Meat");
			setEdible(false);
		}
	}

	@Override
	public boolean isBurnt() {
		return cookedPercentage > 100;
	}

	@Override
	public void chop() {
		if(isChopped())
			return;
		chopState = true;
		setName("Minced Meat");
	}

	@Override
	public boolean isChopped() {
		return chopState;
	}
	
	@Override
	public String toString() {
		return StringUtil.formatNamePercentage(getName(), cookedPercentage);
	}

	public int getCookedPercentage() {
		return cookedPercentage;
	}

	public void setCookedPercentage(int cookedPercentage) {
		this.cookedPercentage = cookedPercentage;
	}


}
