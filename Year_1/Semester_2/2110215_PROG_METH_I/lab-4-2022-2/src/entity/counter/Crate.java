package entity.counter;

import logic.InvalidIngredientException;
import logic.LogicUtil;
import logic.Player;

public class Crate extends Counter {
	private String myIngredient;
	
	public Crate(String s) {
		super(s + " Crate");
		setMyIngredient(s);
	}

	@Override
	public void interact(Player p) {
		if(!p.isHandEmpty() || !isPlacedContentEmpty()) {
			super.interact(p);
			return;
		}
		try {
			p.setHoldingItem(LogicUtil.createIngredientFromName(getMyIngredient()));
		} catch (InvalidIngredientException e) {
			System.out.println(e.getMessage());
		}
		
	}
	
	// getter and setter
	public String getMyIngredient() {
		return myIngredient;
	}

	public void setMyIngredient(String myIngredient) {
		this.myIngredient = myIngredient;
	}
}
