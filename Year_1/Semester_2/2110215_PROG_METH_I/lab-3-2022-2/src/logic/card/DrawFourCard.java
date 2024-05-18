package logic.card;

import logic.game.CardColor;
import logic.game.CardSymbol;
import logic.game.GameLogic;

import java.util.ArrayList;

//You CAN modify the first line
public class DrawFourCard extends EffectCard {

	public DrawFourCard() {
		super(null, CardSymbol.DRAW_FOUR);
	}
	@Override
	public String performEffect() {
		GameLogic gameInstance = GameLogic.getInstance();
		String result = "";
		// Color Step
		setColor(CardColor.RED);
		ArrayList<BaseCard> CurrentPlayerHand = gameInstance.getCurrentPlayerHand();
		if(CurrentPlayerHand.isEmpty());
		else if(CurrentPlayerHand.get(0).getColor() == null);
		else setColor(CurrentPlayerHand.get(0).getColor());
		result += "Set color to " + getColor() + "\n";
		// Draw Step
		gameInstance.incrementDrawAmount(4);
		gameInstance.goToNextPlayer();
		while(gameInstance.getCurrentPlayerHand().isEmpty()) {
			gameInstance.goToNextPlayer();
		}
		CurrentPlayerHand = gameInstance.getCurrentPlayerHand();
		boolean use_card = false;
		for(int i=0; i<CurrentPlayerHand.size(); i++) {
			if(CurrentPlayerHand.get(i).getSymbol() != CardSymbol.DRAW_FOUR) continue;
			result += "Player " + gameInstance.getCurrentPlayer() + " played " + CurrentPlayerHand.get(i) + ". " + (CurrentPlayerHand.size()-1) + " cards remaining.\n";
			result += CurrentPlayerHand.get(i).play();
			use_card = true;
			break;
		}
		if(use_card == false) {
			int drawAmt = gameInstance.draw(gameInstance.getDrawAmount()).size();
			result += "Player " + gameInstance.getCurrentPlayer() + " drew " + drawAmt + " cards. " + CurrentPlayerHand.size() + " cards remaining.";
			gameInstance.setDrawAmount(0);
		}
		return result;
	}

	@Override
	public boolean canPlay() {
		return true;
	}

	@Override
	public String toString() {
		return getSymbol() + (getColor() == null ? "" : " (" + getColor() + " color selected)");
	}
   
}
