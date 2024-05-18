package entity.counter;

import entity.base.Item;
import entity.base.Updatable;
import entity.container.Pan;
import logic.Player;

public class Stove extends Counter implements Updatable {
	public Stove() {
		super("Stove");
	}
	
	public Stove(Item content) {
		super("Stove");
		setPlacedContent(content);
	}
	
	@Override
	public void interact(Player p) {
		if(!isPlacedContentEmpty()) {
			super.interact(p);
			return;
		}
		
		if(p.getHoldingItem() instanceof Pan) {
			super.interact(p);
			return;
		}
			
	}

	@Override
	public void update() {
		if(getPlacedContent() instanceof Pan) {
			((Pan)getPlacedContent()).cook();
		}
	}
}
