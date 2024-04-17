from pydub import AudioSegment

# 加载MP3文件
audio = AudioSegment.from_mp3("E:\\OneDrive\\ccdev\\久石譲 - Mother (映画「菊次郎の夏」より).mp3")

# 设置循环次数
number_of_repeats = 5  # 例如循环5次

# 循环扩充音频
longer_audio = audio * number_of_repeats

# 导出新的MP3文件
longer_audio.export("E:\\OneDrive\\ccdev\\extended_file.mp3", format="mp3")
