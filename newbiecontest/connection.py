import requests
import sys
from utils import trace

class Connection(object):
    def __init__(self, level):
        self.print_debug = trace(level)

    def get(self, url, params=None):
        self.print_debug("Connecting to {}".format(url), 1)
        r = self._get_with_connection(url, params)
        self.print_debug("Response: {}".format(r.text), 3)
        return r

    def _get_with_connection(self, url):
        pass

class NewbieContestConnection(Connection):
    def __init__(self, level):
        super(NewbieContestConnection, self).__init__(level)
        self.base_url = "http://www.newbiecontest.org/epreuves/prog"
        self.session_cookies = {
            "SMFCookie89": "a%3A4%3A%7Bi%3A0%3Bs%3A5%3A%2259439%22%3Bi%3A1%3Bs%3A40%3A%221cec39be45a90de91d9bab83b184139e18a5faf8%22%3Bi%3A2%3Bi%3A1429903859%3Bi%3A3%3Bi%3A0%3B%7D"
              }
    def _get_with_connection(self, url, params):
        try:
            r = requests.get(url, cookies=self.session_cookies, params=params)
        except requests.exceptions.RequestException as e:
            print("Couldn't retrieve the number, request failed with:\n" + e)
            sys.exit(1)
        return r




