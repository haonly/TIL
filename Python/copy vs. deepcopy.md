# list 복사

### shallow copy
```python
import copy
>>> a = [[1,2],[3,4]]
>>> b = copy.copy(a)
>>> a[1].append(5)
>>> a
[[1, 2], [3, 4, 5]]
>>> b
[[1, 2], [3, 4, 5]]
```

## deep copy
```python
>>> import copy
>>> a = [[1,2],[3,4]]
>>> b = copy.deepcopy(a)
>>> a[1].append(5)
>>> a
[[1, 2], [3, 4, 5]]
>>> b
[[1, 2], [3, 4]]
```
