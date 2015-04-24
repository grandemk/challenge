class trace(object):
    def __init__(self, level):
        self.max_level = level;

    def __call__(self, text, level):
        if level <= self.max_level:
            print(text)



