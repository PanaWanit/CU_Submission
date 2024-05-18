package logic.card;

import logic.game.CardColor;
import logic.game.CardSymbol;
import logic.game.GameLogic;
import logic.game.PlayDirection;

//You CAN modify the first line
public class ReverseCard extends EffectCard {
	// TODO Implement here
	public ReverseCard(CardColor color) {
		super(color, CardSymbol.REVERSE);
	}

	public String toString() {
		return getColor() + " " + getSymbol();
	}

	public boolean canPlay() {
		BaseCard top = GameLogic.getInstance().getTopCard();
		return (top.getColor().equals(getColor()) || top.getSymbol().equals(getSymbol()));
	}
	
	public String performEffect() {
		PlayDirection D = GameLogic.getInstance().getPlayDirection().getOpposite();
		GameLogic.getInstance().setPlayDirection(D);
		return "Set direction to " + D; 
	}
}
