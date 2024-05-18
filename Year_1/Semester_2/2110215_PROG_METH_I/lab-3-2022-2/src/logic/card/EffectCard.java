package logic.card;

import java.util.ArrayList;

import logic.game.CardColor;
import logic.game.CardSymbol;
import logic.game.GameLogic;

//You CAN modify the first line
abstract public class EffectCard extends BaseCard {
    public EffectCard(CardColor color, CardSymbol symbol) {
    	super(color, symbol);
    }
    abstract public String performEffect();
    @Override
    abstract public boolean canPlay();
    public String play() {
    	GameLogic gameInstance = GameLogic.getInstance();
		gameInstance.setTopCard(this);
		for(int i=0, is_removed=0; i<gameInstance.getAllPlayerHands().size() && is_removed == 0; i++) {
			for(int j=0; j<gameInstance.getPlayerHand(i).size(); j++) { // must be the same object
				if(this == gameInstance.getPlayerHand(i).get(j)) {
					gameInstance.getPlayerHand(i).remove(j);
					is_removed = 1;
					break;
				}
			}
		}
    	return performEffect();
    }
    

}
