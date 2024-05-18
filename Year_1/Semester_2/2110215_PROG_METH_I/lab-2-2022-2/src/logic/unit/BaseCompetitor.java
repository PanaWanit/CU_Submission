package logic.unit;

public class BaseCompetitor {
	private String name;
	private int power, hp;
	
	public BaseCompetitor(String name) {
		setName(name);
		setPower(3);
		setHp(5);
	}
	public BaseCompetitor(String name, int hp, int power) {
		setName(name);
		setPower(power);
		setHp(hp);
	} 
	public void attack(BaseCompetitor enemy) {
		int enemyHp = enemy.getHp() - power;
		enemy.setHp(enemyHp);
	}
	public String getType() {
		if(this instanceof Sorcerer)
			return "Sorcerer";
		if(this instanceof Tiger)
			return "Tiger";
		if(this instanceof ToughMan)
			return "ToughMan";
		if(this instanceof BaseCompetitor)
			return "BaseCompetitor";
		return "Error!";
	}
	
	
	// getter and setter
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getPower() {
		return power;
	}
	public void setPower(int power) {
		this.power = Math.max(1, power);
	}
	public int getHp() {
		return hp;
	}
	public void setHp(int hp) {
		this.hp = Math.max(0, hp);
	}
}