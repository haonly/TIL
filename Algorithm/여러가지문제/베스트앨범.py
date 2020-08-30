from collections import defaultdict
from operator import itemgetter

def solution(genres, plays):
    answer = []
    
    genre_rank_dict = defaultdict(lambda: 0)
    genre_play_dict = defaultdict(list)
    
    for genre, play in zip(genres, plays):
        genre_rank_dict[genre] += play
    
    genre_rank = [genre for genre, play in sorted(genre_rank_dict.items(), key=itemgetter(1), reverse=True)]
    
    for i, genre_play_tuple in enumerate(zip(genres, plays)):
        genre_play_dict[genre_play_tuple[0]].append((genre_play_tuple[1], i))

    for genre in genre_rank:
        tmp_list = sorted(genre_play_dict[genre], key=itemgetter(0), reverse=True)
        if len(tmp_list) > 1:
            answer.append(tmp_list[0][1])
            answer.append(tmp_list[1][1])
        else:
            answer.append(tmp_list[0][1])
        
    return answer