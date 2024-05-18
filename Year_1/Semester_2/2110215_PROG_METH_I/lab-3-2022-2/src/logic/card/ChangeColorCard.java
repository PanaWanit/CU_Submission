package logic.card;

import logic.game.CardColor;
import logic.game.CardSymbol;
import logic.game.GameLogic;

import java.util.ArrayList;

//You CAN modify the first line
public class ChangeColorCard extends EffectCard {

	public ChangeColorCard() {
		super(null, CardSymbol.CHANGE_COLOR);
	}
	@Override
	public String performEffect() {
		setColor(CardColor.RED);
		ArrayList<BaseCard> CurrentPlayerHand = GameLogic.getInstance().getCurrentPlayerHand();
		if(CurrentPlayerHand.isEmpty());
		else if(CurrentPlayerHand.get(0).getColor() == null);
		else setColor(CurrentPlayerHand.get(0).getColor());
		return "Set color to " + getColor();
	}

	@Override
	public boolean canPlay() {
		return true;
	}

	@Override
	public String toString() {
		return getSymbol() + (getColor() == null ? "" : " (" + getColor() + " color selected)" ); 
	}
    // TODO Implement here
	

}
