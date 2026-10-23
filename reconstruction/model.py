"""New reconstruction, 2026-10-23. Demo inputs are synthetic, not historical results."""
class Lock:
    def __init__(self):self.until=0;self.last_match=None
    def step(self,now,match_id=None,authorized_ids=(),sensor_ok=True):
        if not sensor_ok:self.until=0;return False
        if match_id is None:self.last_match=None
        if match_id is not None and match_id!=self.last_match:
            self.last_match=match_id
            if match_id in authorized_ids and now>=self.until:self.until=now+3
        return now<self.until
def demo():
    c=Lock();assert not c.step(1,8,(1,2));assert c.step(2,1,(1,2))
    assert not c.step(6,1,(1,2));c.step(7)
    assert c.step(8,1,(1,2));assert not c.step(9,sensor_ok=False)
    return {'timeout_relocks':True,'repeated_match_does_not_extend':True}

if __name__ == "__main__":
    import json
    print(json.dumps(demo(), indent=2))
