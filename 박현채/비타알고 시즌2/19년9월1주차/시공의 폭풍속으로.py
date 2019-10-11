TEAM_SELECT_HERO = []
USER_SELECT_HERO = []
USEABLE_HERO = []

TEAM_SELECT_HERO.extend(map(int, input().split())) 
USER_SELECT_HERO.extend(map(int, input().split()))

USEABLE_HERO = list(set(USER_SELECT_HERO) - set(TEAM_SELECT_HERO)) # 사용자 선택 영웅의 리스트 집합 - 팀 선택 영웅의 리스트 집합

print(len(USEABLE_HERO)) # 사용가능 영웅 리스트 길이 출력