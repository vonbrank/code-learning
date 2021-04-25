

def sortZDepth(self, kp):
      self.zDepthRank = np.zeros(kp.shape[0])
       for i in range(0, kp.shape[0]):
            self.zDepthRank[i] = 0
            cnt = 0
            for j in range(0, 25):
                if kp[i][j][0] == 0 and kp[i][j][1] == 0:
                    continue
                cnt += 1
                self.zDepthRank[i] += kp[i][j][2]
            self.zDepthRank[i] /= cnt
        self.zDepthRank = np.argsort(self.zDepthRank)
