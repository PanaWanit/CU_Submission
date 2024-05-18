package entity.ingredient;

import entity.base.Choppable;
import entity.base.Ingredient;

public class Lettuce extends Ingredient implements Choppable {
	private boolean chopState;
	public Lettuce() {
		super("Lettuce");
		setEdible(true);
		this.chopState = false;
	}

	@Override
	public void chop() {
		if(isChopped())
			return;
		chopState = true;
		setName("Chopped Lettuce");
	}

	@Override
	public boolean isChopped() {
		return chopState;
	}
	
}
