package entity.counter;

import entity.base.Updatable;
import entity.container.Dish;
import logic.Player;

public class DishWasher extends Counter implements Updatable{

	public DishWasher() {
		super("Dish Washer");
	}
	@Override
	public void interact(Player p) {
		if(!isPlacedContentEmpty()) {
			super.interact(p);
			return;
		}
		if(p.getHoldingItem() instanceof Dish && ((Dish)p.getHoldingItem()).isDirty()) {
			super.interact(p);
		}
			
	}
	@Override
	public void update() {
		if(getPlacedContent() instanceof Dish) {
			((Dish)getPlacedContent()).clean(15);
		}
	}

}
