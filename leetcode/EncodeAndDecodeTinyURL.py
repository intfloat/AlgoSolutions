from random import randint

class Codec:

    ch_list = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789'

    def __init__(self):
        self.forward_mp = {}
        self.backward_mp = {}

    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.

        :type longUrl: str
        :rtype: str
        """
        while True:
            s = 'http://tinyurl.com/' + self._get_random_str()
            if not s in self.forward_mp:
                self.forward_mp[longUrl] = s
                self.backward_mp[s] = longUrl
                return s

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.

        :type shortUrl: str
        :rtype: str
        """
        return self.backward_mp[shortUrl]

    def _get_random_str(self):
        return ''.join([Codec.ch_list[randint(0, len(Codec.ch_list) - 1)] for i in range(10)])

# Your Codec object will be instantiated and called as such:
codec = Codec()
s = codec.encode('http://baidu.com')
print(s)
print(codec.decode(s))
