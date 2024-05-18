package logic.card;

import logic.game.CardSymbol;

import java.util.ArrayList;
import logic.game.CardColor;
import logic.game.GameLogic;

//You CAN modify the first line
public class NumberCard extends BaseCard {
	// TODO Implement here
	public NumberCard(CardColor color, CardSymbol symbol) {
		super(color, symbol);
	}
	
	@Override
	public String toString() {
		return getColor() + " " + getSymbol();
	}

	@Override
	public boolean canPlay() {
		BaseCard top = GameLogic.getInstance().getTopCard();
		return (top.getColor().equals(getColor()) || top.getSymbol().equals(getSymbol()));
	}

	@Override
	public String play() {
		GameLogic gameInstance = GameLogic.getInstance();
		gameInstance.setTopCard(this);
		for(int i=0, is_removed=0; i<gameInstance.getAllPlayerHands().size() && is_removed == 0; i++) {
			for(int j=0; j<gameInstance.getPlayerHand(i).size(); j++) {
				if(this == gameInstance.getPlayerHand(i).get(j)) { // same object
					gameInstance.getPlayerHand(i).remove(j);
					is_removed = 1;
					break;
				}
			}
		}
		return null;
	}
}
