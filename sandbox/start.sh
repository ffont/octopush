# If python server is running, kill it
PID=`ps -eaf | grep "python server.py" | grep -v grep | awk '{print $2}'`
if [[ "" !=  "$PID" ]]; then
  echo "* Killing existing python server with PID $PID"
  kill -9 $PID
fi

# Start python server and wait a few seconds
echo "* Starting python server..."
python server.py &
sleep 5

# Start sushi with octopush plugin
echo "* Starting sushi..."
sushi -r -c /home/mind/octopush_sushi_config.json
