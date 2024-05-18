package logic.unit;

public class Sorcerer extends BaseCompetitor {

	public Sorcerer(String name) {
		super(name, 4, 2);
	}
	public Sorcerer(String name, int hp, int power) {
		super(name, hp, power);
	}

	public void lowerPower(BaseCompetitor enemy, int powerDown) {
		powerDown = Math.max(powerDown, 0);
		int enemy_power = Math.max(1, enemy.getPower() - powerDown);
		enemy.setPower(enemy_power);
	}

	@Override
	public void attack(BaseCompetitor enemy) {
		if (enemy.getType().equals("Tiger")) {
			int enemyHp = enemy.getHp() - getPower()/2;
			enemy.setHp(enemyHp);
		}
		else if(enemy.getType().equals("Sorcerer") || enemy.getType().equals("BaseCompetitor")) {
			super.attack(enemy);
		}
		else {
			int enemyHp = enemy.getHp() - 3*getPower()/2;
			enemy.setHp(enemyHp);
		}
	}

}
